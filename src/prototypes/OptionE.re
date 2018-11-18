/*
    Use deriving abstract again, and make API nicer
*/

module HotpanelProto = {
  module ActivationPlaceEnum = {
    type t =
      | ActivationPlaceMyProfile
      | ActivationPlaceDiscover;
  };

  module ActionTypeEnum = {
    type t =
      | ActivationTypeClick
      | ActivationTypeConfirm;
  };

  module ViewProfileEvent = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      encrypted_user_id: string,
      [@bs.optional]
      activation_place: ActivationPlaceEnum.t,
    };
  };

  module ActionEvent = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      action_type: ActionTypeEnum.t,
    };
  };

  module Event = {
    type t =
      | ActionEvent(ActionEvent.t)
      | ViewProfileEvent(ViewProfileEvent.t);
  };
  module EventBody = {
    type t = {. "view_profile": option(ViewProfileEvent.t)};
  };
};

module HotpanelAPI = {
  let track = (event: HotpanelProto.Event.t) => {
    let body = switch (event) {
    | ActionEvent(e) => Js.Json.stringifyAny(e)
    | ViewProfileEvent(e) => Js.Json.stringifyAny(e)
    };

    Js.log(body);
  };
};

module Hotpanel = {
  include HotpanelProto;
  include HotpanelAPI;
};

let userId = "123456";

Hotpanel.(
  track(
    ViewProfileEvent(
      ViewProfileEvent.t(
        ~encrypted_user_id=userId,
        ~activation_place=ActivationPlaceEnum.ActivationPlaceDiscover,
        (),
      ),
    ),
  )
);
