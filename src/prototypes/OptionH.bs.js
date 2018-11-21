// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var CamlinternalOO = require("bs-platform/lib/js/camlinternalOO.js");

function tToJs(param) {
  return param + 1 | 0;
}

function tFromJs(param) {
  if (param <= 2 && 1 <= param) {
    return param - 1 | 0;
  }
  
}

var ActivationPlaceEnum = /* module */[
  /* tToJs */tToJs,
  /* tFromJs */tFromJs
];

function tToJs$1(param) {
  return param + 1 | 0;
}

function tFromJs$1(param) {
  if (!(param <= 2 && 1 <= param)) {
    Js_exn.raiseError("ASSERT FAILURE");
  }
  return param - 1 | 0;
}

var ActionTypeEnum = /* module */[
  /* tToJs */tToJs$1,
  /* tFromJs */tFromJs$1
];

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

var b = Date.now();

function eventToEventName($$event) {
  if ($$event) {
    return "EVENT_NAME_VIEW_PROFILE";
  } else {
    return "EVENT_NAME_ACTION";
  }
}

function sendBody(body) {
  var sendableBody = JSON.stringify(body);
  console.log(sendableBody === undefined ? undefined : Js_primitive.some(sendableBody));
  return /* () */0;
}

function track($$event, eventBody) {
  var eventName = $$event ? "EVENT_NAME_VIEW_PROFILE" : "EVENT_NAME_ACTION";
  return sendBody(/* record */[
              /* event */$$event,
              /* body */eventBody,
              /* name */eventName,
              /* ts */Date.now() | 0
            ]);
}

var HotpanelAPI = /* module */[
  /* b */b,
  /* eventToEventName */eventToEventName,
  /* sendBody */sendBody,
  /* track */track
];

var Hotpanel = /* module */[
  /* ActivationPlaceEnum */ActivationPlaceEnum,
  /* ActionTypeEnum */ActionTypeEnum,
  /* ViewProfileEvent */ViewProfileEvent,
  /* ActionEvent */ActionEvent,
  /* Event */Event,
  /* EventBody */EventBody,
  /* b */b,
  /* eventToEventName */eventToEventName,
  /* sendBody */sendBody,
  /* track */track
];

var class_tables = [
  0,
  0,
  0
];

function encode(param) {
  if (!class_tables[0]) {
    var $$class = CamlinternalOO.create_table(0);
    var env = CamlinternalOO.new_variable($$class, "");
    var env_init = function (env$1) {
      var self = CamlinternalOO.create_object_opt(0, $$class);
      self[env] = env$1;
      return self;
    };
    CamlinternalOO.init_class($$class);
    class_tables[0] = env_init;
  }
  return Curry._1(class_tables[0], 0);
}

var class_tables$1 = [
  0,
  0,
  0
];

function decode(param) {
  if (!class_tables$1[0]) {
    var $$class = CamlinternalOO.create_table(0);
    var env = CamlinternalOO.new_variable($$class, "");
    var env_init = function (env$1) {
      var self = CamlinternalOO.create_object_opt(0, $$class);
      self[env] = env$1;
      return self;
    };
    CamlinternalOO.init_class($$class);
    class_tables$1[0] = env_init;
  }
  return Curry._1(class_tables$1[0], 0);
}

var Protobuf = /* module */[
  /* encode */encode,
  /* decode */decode
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
exports.Protobuf = Protobuf;
exports.userId = userId;
/* b Not a pure module */
