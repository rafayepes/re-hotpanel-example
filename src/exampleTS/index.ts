import { track } from './HotpanelAPITS.gen';
import {
    Event_ViewProfileEvent,
    Event_ActionEvent,
    ActionTypeEnum_ActivationTypeClick,
    ActivationPlaceEnum_ActivationPlaceDiscover,
} from './HotpanelProtoTS.gen';
let userId = '123456';

track(
    Event_ViewProfileEvent({
        encrypted_user_id: userId,
        activation_place: ActivationPlaceEnum_ActivationPlaceDiscover,
    })
);

track(
    Event_ActionEvent({
        action_type: ActionTypeEnum_ActivationTypeClick,
    })
);
