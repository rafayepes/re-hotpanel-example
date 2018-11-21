module ActivationPlaceEnum = {
  [@genType]
  type t =
    | ActivationPlaceMyProfile
    | ActivationPlaceDiscover;
};

module ActionTypeEnum = {
  [@genType]
  type t =
    | ActivationTypeClick
    | ActivationTypeConfirm;
};

module ViewProfileEvent = {
  [@genType]
  type t = {
    encrypted_user_id: option(string),
    activation_place: option(ActivationPlaceEnum.t),
  };
};

module ActionEvent = {
  [@genType]
  type t = {action_type: option(ActionTypeEnum.t)};
};

module Event = {
  [@genType]
  type t =
    | ActionEvent(ActionEvent.t)
    | ViewProfileEvent(ViewProfileEvent.t);
};
module EventBody = {
  type t = {. "view_profile": option(ViewProfileEvent.t)};
};
