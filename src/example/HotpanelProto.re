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
