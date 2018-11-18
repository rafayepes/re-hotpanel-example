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
    [@bs.optional] [@bs.as "encrypted_user_id"]
    encryptedUserId: string,
    [@bs.optional] [@bs.as "activation_place"]
    activationPlace: ActivationPlaceEnum.t,
  };
};

module ActionEvent = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "action_type"]
    actionType: ActionTypeEnum.t,
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
