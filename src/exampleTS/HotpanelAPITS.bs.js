// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function eventToEventName($$event) {
  if ($$event.tag) {
    return "EVENT_NAME_VIEW_PROFILE";
  } else {
    return "EVENT_NAME_ACTION";
  }
}

function stringifyEventBody($$event) {
  return Js_primitive.undefined_to_opt(JSON.stringify($$event[0]));
}

function sendBody(body) {
  var sendableBody = JSON.stringify(body);
  console.log(sendableBody === undefined ? undefined : Js_primitive.some(sendableBody));
  return /* () */0;
}

function track($$event) {
  var eventName = eventToEventName($$event);
  var eventBody = stringifyEventBody($$event);
  if (eventBody !== undefined) {
    return sendBody(/* record */[
                /* body */eventBody,
                /* name */eventName,
                /* ts */Date.now() | 0
              ]);
  } else {
    return /* () */0;
  }
}

exports.eventToEventName = eventToEventName;
exports.stringifyEventBody = stringifyEventBody;
exports.sendBody = sendBody;
exports.track = track;
/* No side effect */