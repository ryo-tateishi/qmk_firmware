#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum
{
  _NUM = 0,
  _FN,
  _BLE
};

enum custom_keycodes
{
  NUM = SAFE_RANGE,
  FN,
  P00,
  AD_WO_L, /* Start advertising without whitelist  */
  BLE_DIS, /* Disable BLE HID sending              */
  BLE_EN,  /* Enable BLE HID sending               */
  USB_DIS, /* Disable USB HID sending              */
  USB_EN,  /* Enable USB HID sending               */
  DELBNDS, /* Delete all bonding                   */
  ADV_ID0, /* Start advertising to PeerID 0        */
  ADV_ID1, /* Start advertising to PeerID 1        */
  ADV_ID2, /* Start advertising to PeerID 2        */
  ADV_ID3, /* Start advertising to PeerID 3        */
  ADV_ID4, /* Start advertising to PeerID 4        */
  BATT_LV, /* Display battery level in milli volts */
  DEL_ID0, /* Delete bonding of PeerID 0           */
  DEL_ID1, /* Delete bonding of PeerID 1           */
  DEL_ID2, /* Delete bonding of PeerID 2           */
  DEL_ID3, /* Delete bonding of PeerID 3           */
  DEL_ID4, /* Delete bonding of PeerID 4           */
  ENT_DFU, /* Start bootloader                     */
  ENT_SLP, /* Deep sleep mode                      */
};

//extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUM] = LAYOUT(
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, LT(_BLE, KC_ESC),
        KC_P7, KC_P8, KC_P9, KC_PPLS, LT(_FN, KC_SLCK),
        KC_P4, KC_P5, KC_P6, S(KC_TAB), KC_PSCR,
        KC_P1, KC_P2, KC_P3, KC_TAB, KC_DEL,
        KC_P0, P00, KC_PDOT, KC_PENT, KC_BSPC),

    [_FN] = LAYOUT(
        KC_F10, KC_F11, KC_F12, _______, _______,
        KC_F7, KC_F8, KC_F9, _______, _______,
        KC_F4, KC_F5, KC_F6, _______, _______,
        KC_F1, KC_F2, KC_F3, _______, _______,
        XXXXXXX, _______, _______, _______, _______),

    [_BLE] = LAYOUT(
        AD_WO_L, BLE_EN, USB_EN, BATT_LV, _______,
        DELBNDS, BLE_DIS, USB_DIS, ENT_SLP, XXXXXXX,
        ADV_ID4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        ADV_ID1, ADV_ID2, ADV_ID3, XXXXXXX, ENT_DFU,
        ADV_ID0, DEL_ID0, DEL_ID1, DEL_ID2, DEL_ID3)};



/* void matrix_init_user(void) {
    set_usb_enabled(true);
} */

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  char str[16];
  if (record->event.pressed)
  {
    switch (keycode)
    {
    case P00:
      SEND_STRING("00");
      return false;
      break;
    case DELBNDS:
      delete_bonds();
      return false;
      break;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
      break;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV ", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    default:
      break;
    }
  }
  else if (!record->event.pressed)
  {
    switch (keycode)
    {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
      break;
    default:
      break;
    }
  }
  return true;
}
