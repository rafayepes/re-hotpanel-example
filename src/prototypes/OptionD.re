/*
  Make track function generic, so that accepts different events, not only
  ViewProfile event.
*/

module Hotpanel = {
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
    type t = {
      .
      "encrypted_user_id": option(string),
      "activation_place": option(ActivationPlaceEnum.t),
    };
  };

  module ActionEvent = {
    type t = {. "action_type": option(ActionTypeEnum.t)};
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
  let track = (event: Hotpanel.Event.t) => {/* TODO */};
};

let userId = "123456";

HotpanelAPI.track(
  Hotpanel.Event.ViewProfileEvent({
    "encrypted_user_id": Some(userId),
    "activation_place":
      Some(Hotpanel.ActivationPlaceEnum.ActivationPlaceDiscover),
  }),
);
