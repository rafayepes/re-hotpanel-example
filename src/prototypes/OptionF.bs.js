// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

var ActivationPlaceEnum = /* module */[];

var ActionTypeEnum = /* module */[];

var ViewProfileEvent = /* module */[];

var ActionEvent = /* module */[];

var Event = /* module */[];

var EventBody = /* module */[];

var HotpanelProto = /* module */[
  /* ActivationPlaceEnum */ActivationPlaceEnum,
  /* ActionTypeEnum */ActionTypeEnum,
  /* ViewProfileEvent */ViewProfileEvent,
  /* ActionEvent */ActionEvent,
  /* Event */Event,
  /* EventBody */EventBody
];

function track($$event, eventBody) {
  var body = JSON.stringify(eventBody);
  console.log(body === undefined ? undefined : Js_primitive.some(body));
  return /* () */0;
}

var HotpanelAPI = /* module */[/* track */track];

var Hotpanel = /* module */[
  /* ActivationPlaceEnum */ActivationPlaceEnum,
  /* ActionTypeEnum */ActionTypeEnum,
  /* ViewProfileEvent */ViewProfileEvent,
  /* ActionEvent */ActionEvent,
  /* Event */Event,
  /* EventBody */EventBody,
  /* track */track
];

var userId = "123456";

track(/* ViewProfileEvent */1, {
      encrypted_user_id: userId,
      activation_place: /* ActivationPlaceDiscover */1
    });

track(/* ActionEvent */0, {
      action_type: /* ActivationTypeClick */0
    });

exports.HotpanelProto = HotpanelProto;
exports.HotpanelAPI = HotpanelAPI;
exports.Hotpanel = Hotpanel;
exports.userId = userId;
/*  Not a pure module */
