let track = (event: HotpanelProto.Event.t) => {
  let body =
    switch (event) {
    | ActionEvent(e) => Js.Json.stringifyAny(e)
    | ViewProfileEvent(e) => Js.Json.stringifyAny(e)
    };

  Js.log(body);
};
