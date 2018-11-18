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
