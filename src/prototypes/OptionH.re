/* TODO: Encode, decode */

module HotpanelProto = {
  module ActivationPlaceEnum = {
    [@bs.deriving jsConverter]
    type t =
      | [@bs.as 1] ActivationPlaceMyProfile
      | [@bs.as 2] ActivationPlaceDiscover;
  };

  module ActionTypeEnum = {
    /* Note difference in deriving from above */
    [@bs.deriving {jsConverter: newType}]
    type t =
      | [@bs.as 1] ActivationTypeClick
      | [@bs.as 2] ActivationTypeConfirm;
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

  /* let eventToEventName = (type a, event: HotpanelProto.Event.t(a), evwentBody: a) => {
       switch(event) {
         | ViewProfileEvent => "asd"
       }
     } */

  let b = Js.Date.now();

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
      event: event,
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

module Protobuf = {
  let encode = () => {};

  let decode = () => {};
};

let userId = "123456";

Hotpanel.(
  track(
    ViewProfileEvent,
    ViewProfileEvent.t(
      ~encrypted_user_id=userId,
      ~activation_place=ActivationPlaceEnum.ActivationPlaceDiscover,
      (),
    ),
  )
);

Hotpanel.(
  track(
    ActionEvent,
    ActionEvent.t(~action_type=ActionTypeEnum.ActivationTypeClick, ()),
  )
);
