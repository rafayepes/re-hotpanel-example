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
  activation_place: None /* activation_place: 3, */ /* Doesn't compile. Yay! */
});

trackViewProfileEvent({
  encrypted_user_id: Some(userId),
  activation_place: None /* activation_place: ActionTypeEnum.ActivationTypeClick, */ /* Doesn't compile. Yay! */
}) /* let userId2 = getUserId() + 1; */; /* Doesn't compile. Yay! */

/* User ID, strings and numbers */

/* let userId3 = getUserId() + ActivationPlaceEnum.ACTIVATION_PLACE_DISCOVER; /* Compiles =/; // Compiles =/ */ */
