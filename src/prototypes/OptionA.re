/* Basic version with concrete tracking function for ViewProfileEvent */

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
    encrypted_user_id: option(string),
    activation_place: option(ActivationPlaceEnum.t),
  };
};

let trackViewProfileEvent = (event: ViewProfileEvent.t) =>
  switch (event.encrypted_user_id) {
  | Some(userId) => Js.log(userId ++ "as")
  | None => ()
  };

let getUserId = () =>
  string_of_int(Js.Math.floor(Js.Math.random() *. 100000.0));

let userId = getUserId();

trackViewProfileEvent({
  encrypted_user_id: Some(userId),
  activation_place: Some(ActivationPlaceEnum.ActivationPlaceDiscover),
});

trackViewProfileEvent({
  encrypted_user_id: Some(userId),
  activation_place: None,
});

trackViewProfileEvent({
  encrypted_user_id: Some(userId),
  activation_place: None,
});
