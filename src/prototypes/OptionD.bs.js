// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var CamlinternalOO = require("bs-platform/lib/js/camlinternalOO.js");

var ActivationPlaceEnum = /* module */[];

var ActionTypeEnum = /* module */[];

var ViewProfileEvent = /* module */[];

var ActionEvent = /* module */[];

var Event = /* module */[];

var EventBody = /* module */[];

var Hotpanel = /* module */[
  /* ActivationPlaceEnum */ActivationPlaceEnum,
  /* ActionTypeEnum */ActionTypeEnum,
  /* ViewProfileEvent */ViewProfileEvent,
  /* ActionEvent */ActionEvent,
  /* Event */Event,
  /* EventBody */EventBody
];

var class_tables = [
  0,
  0,
  0
];

function track($$event) {
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

var HotpanelAPI = /* module */[/* track */track];

var userId = "123456";

track(/* ViewProfileEvent */Block.__(1, [{
          encrypted_user_id: userId,
          activation_place: /* ActivationPlaceDiscover */1
        }]));

exports.Hotpanel = Hotpanel;
exports.HotpanelAPI = HotpanelAPI;
exports.userId = userId;
/*  Not a pure module */
