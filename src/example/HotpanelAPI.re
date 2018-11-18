type eventsParams = {
  body: string,
  name: string,
  ts: int,
};

let eventToEventName = (event: HotpanelProto.Event.t) =>
  HotpanelProto.Event.(
    switch (event) {
    | ViewProfileEvent(_) => "EVENT_NAME_VIEW_PROFILE"
    | ActionEvent(_) => "EVENT_NAME_ACTION"
    }
  );

let stringifyEventBody = (event: HotpanelProto.Event.t) =>
  switch (event) {
  | ViewProfileEvent(e) => Js.Json.stringifyAny(e)
  | ActionEvent(e) => Js.Json.stringifyAny(e)
  };

let sendBody = (body: eventsParams) => {
  let sendableBody = Js.Json.stringifyAny(body);

  Js.log(sendableBody);
};

let track = (event: HotpanelProto.Event.t) => {
  let eventName = eventToEventName(event);
  let eventBody = stringifyEventBody(event);

  switch (eventBody) {
  | Some(body) =>
    sendBody({body, name: eventName, ts: int_of_float(Js.Date.now())})
  | None => ()
  };
};
