/* GADT's and add eventToEventName and sendBody functions */

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
    type t('a) =
      | ActionEvent: t(ActionEvent.t)
      | ViewProfileEvent: t(ViewProfileEvent.t);
  };

  module EventBody = {
    type t = {. "view_profile": option(ViewProfileEvent.t)};
  };
};

module HotpanelAPI = {
  type eventsParams('a) = {
    event: HotpanelProto.Event.t('a),
    body: 'a,
    name: string,
    ts: int,
  };

  let eventToEventName = (type a, event: HotpanelProto.Event.t(a)) =>
    HotpanelProto.Event.(
      switch (event) {
      | ViewProfileEvent => "EVENT_NAME_VIEW_PROFILE"
      | ActionEvent => "EVENT_NAME_ACTION"
      }
    );

  let sendBody = (body: eventsParams('a)) => {
    let sendableBody = Js.Json.stringifyAny(body);

    Js.log(sendableBody);
  };

  let track = (event: HotpanelProto.Event.t('a), eventBody: 'a) => {
    /* Initially implemented this pattern matching, but seems unnnecesarry? */
    let eventName = eventToEventName(event);

    sendBody({
      event,
      body: eventBody,
      name: eventName,
      ts: int_of_float(Js.Date.now()),
    });
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
