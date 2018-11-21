type eventsParams = {
  body: string,
  name: string,
  ts: int,
};

let eventToEventName = (event: HotpanelProtoTS.Event.t) =>
  HotpanelProtoTS.Event.(
    switch (event) {
    | ViewProfileEvent(_) => "EVENT_NAME_VIEW_PROFILE"
    | ActionEvent(_) => "EVENT_NAME_ACTION"
    }
  );

let stringifyEventBody = (event: HotpanelProtoTS.Event.t) =>
  switch (event) {
  | ViewProfileEvent(e) => Js.Json.stringifyAny(e)
  | ActionEvent(e) => Js.Json.stringifyAny(e)
  };

let sendBody = (body: eventsParams) => {
  let sendableBody = Js.Json.stringifyAny(body);

  Js.log(sendableBody);
};

[@genType]
let track = (event: HotpanelProtoTS.Event.t) => {
  let eventName = eventToEventName(event);
  let eventBody = stringifyEventBody(event);

  switch (eventBody) {
  | Some(body) =>
    sendBody({body, name: eventName, ts: int_of_float(Js.Date.now())})
  | None => ()
  };
};
