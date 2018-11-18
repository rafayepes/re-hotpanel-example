let userId = "123456";

Hotpanel.(
  track(
    ViewProfileEvent(
      ViewProfileEvent.t(
        ~encryptedUserId=userId,
        ~activationPlace=ActivationPlaceEnum.ActivationPlaceDiscover,
        (),
      ),
    ),
  )
);

Hotpanel.(
  track(
    ActionEvent(
      ActionEvent.t(~actionType=ActionTypeEnum.ActivationTypeClick, ()),
    ),
  )
);
