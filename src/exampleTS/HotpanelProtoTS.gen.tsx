/* TypeScript file generated by genType. */

// tslint:disable-next-line:no-var-requires
const CreateBucklescriptBlock = require('bs-platform/lib/js/block.js');

// tslint:disable-next-line:max-classes-per-file 
export abstract class ActivationPlaceEnum_TActivationPlaceMyProfile { protected opaque!: any }; /* simulate opaque types */

export const ActivationPlaceEnum_ActivationPlaceMyProfile: ActivationPlaceEnum_TActivationPlaceMyProfile = 0 as any;

// tslint:disable-next-line:max-classes-per-file 
export abstract class ActivationPlaceEnum_TActivationPlaceDiscover { protected opaque!: any }; /* simulate opaque types */

export const ActivationPlaceEnum_ActivationPlaceDiscover: ActivationPlaceEnum_TActivationPlaceDiscover = 1 as any;

export type ActivationPlaceEnum_t =
  | ActivationPlaceEnum_TActivationPlaceMyProfile
  | ActivationPlaceEnum_TActivationPlaceDiscover;

// tslint:disable-next-line:max-classes-per-file 
export abstract class ActionTypeEnum_TActivationTypeClick { protected opaque!: any }; /* simulate opaque types */

export const ActionTypeEnum_ActivationTypeClick: ActionTypeEnum_TActivationTypeClick = 0 as any;

// tslint:disable-next-line:max-classes-per-file 
export abstract class ActionTypeEnum_TActivationTypeConfirm { protected opaque!: any }; /* simulate opaque types */

export const ActionTypeEnum_ActivationTypeConfirm: ActionTypeEnum_TActivationTypeConfirm = 1 as any;

export type ActionTypeEnum_t =
  | ActionTypeEnum_TActivationTypeClick
  | ActionTypeEnum_TActivationTypeConfirm;

// tslint:disable-next-line:interface-over-type-literal
export type ViewProfileEvent_t = {readonly encrypted_user_id?: string, readonly activation_place?: ActivationPlaceEnum_t};

// tslint:disable-next-line:interface-over-type-literal
export type ActionEvent_t = {readonly action_type?: ActionTypeEnum_t};

// tslint:disable-next-line:max-classes-per-file 
export abstract class Event_TActionEvent { protected opaque!: any }; /* simulate opaque types */

export const Event_ActionEvent: (_1:ActionEvent_t) => Event_TActionEvent = function _(Arg1) { return CreateBucklescriptBlock.__(0 as any, [[Arg1.action_type]]) }

// tslint:disable-next-line:max-classes-per-file 
export abstract class Event_TViewProfileEvent { protected opaque!: any }; /* simulate opaque types */

export const Event_ViewProfileEvent: (_1:ViewProfileEvent_t) => Event_TViewProfileEvent = function _(Arg1) { return CreateBucklescriptBlock.__(1 as any, [[Arg1.encrypted_user_id, Arg1.activation_place]]) }

export type Event_t =
  | Event_TActionEvent
  | Event_TViewProfileEvent;