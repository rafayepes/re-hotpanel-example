/* GADT's and camelCase instead of snake case for record properties*/

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
      [@bs.as "encrypted_user_id"]
      encryptedUserId: string,
      [@bs.optional]
      [@bs.as "activation_place"]
      activationPlace: ActivationPlaceEnum.t,
    };
  };

  module ActionEvent = {
    [@bs.deriving abstract]
    type t = {
      [@bs.optional]
      [@bs.as "action_type"]
      actionType: ActionTypeEnum.t,
    };
  };

  module Event = {
    type t('a) =
      | ActionEvent: t(ActionEvent.t)
      | ViewProfileEvent: t(ViewProfileEvent.t);
  };
  module EventBody = {
    type t = {. "view_profile": option(ViewProfileEvent.t)};
  };
};

module HotpanelAPI = {
  let track = (type a, event: HotpanelProto.Event.t(a), eventBody: a) => {
    /* Initially implemented this pattern matching, but seems unnnecesarry? */
    /* let body = switch (event) {
       | ViewProfileEvent => Js.Json.stringifyAny(eventBody)
       | ActionEvent => Js.Json.stringifyAny(eventBody)
       }; */

    let body = Js.Json.stringifyAny(eventBody);

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
    ViewProfileEvent,
    ViewProfileEvent.t(
      ~encryptedUserId=userId,
      ~activationPlace=ActivationPlaceEnum.ActivationPlaceDiscover,
      (),
    ),
  )
);

Hotpanel.(
  track(
    ActionEvent,
    ActionEvent.t(~actionType=ActionTypeEnum.ActivationTypeClick, ()),
  )
);
