/*
  Now instead of creating record manually, which requires to list all
  properties with Some/None, now we use @bs.deriving abstract instead.
 */

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

let trackViewProfileEvent = (event: ViewProfileEvent.t) =>
  switch (ViewProfileEvent.encrypted_user_idGet(event)) {
  | Some(userId) => Js.log(userId ++ "as")
  | None => ()
  };

let getUserId = () =>
  string_of_int(Js.Math.floor(Js.Math.random() *. 100000.0));

let userId = getUserId();

trackViewProfileEvent(
  ViewProfileEvent.t(
    ~encrypted_user_id=userId,
    ~activation_place=ActivationPlaceEnum.ActivationPlaceDiscover,
    (),
  ),
);

trackViewProfileEvent(ViewProfileEvent.t(~encrypted_user_id=userId, ()));
