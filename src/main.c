#include <zephyr/types.h>
#include <stddef.h>
#include <errno.h>
#include <zephyr/kernel.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

#include <bluetooth/scan.h>
#include <bluetooth/services/hogp.h>
#include <dk_buttons_and_leds.h>

#include <zephyr/sys/byteorder.h>

#include <dk_buttons_and_leds.h>

#include <zephyr/settings/settings.h>

static struct bt_conn *ds4_conn;
static struct bt_hogp hogp;
static struct bt_conn *auth_conn;



/* HID protocol stuff */

static void hogp_ready_cb(void){
    printf("HID instance initialized");
    /* Start HID listening thingy */
}

static void hogp_fail_cb(void){
    printf("HID instance initialization failed");
}

static void hogp_update_cb(){
    printf("HID instance protocol updated");
}

struct bt_hogp_init_params hogp_parameters = {
    .ready_cb = hogp_ready_cb,
    .prep_error_cb = hogp_fail_cb,
    .pm_update_cb = hogp_update_cb
};



/* Bluetooth auth stuff */

static void bt_auth_display_cb(void){

}

static void bt_auth_confirm_cb(void){

}

static void bt_auth_cancel_cb(void){

}

struct bt_conn_auth_cb authentication_callbacks = {
    .passkey_confirm = bt_auth_confirm_cb,
    .passkey_display = bt_auth_display_cb ,    
    .cancel = bt_auth_cancel_cb
}

int main(void)
{
    /* STEP 1 intit hogp*/
    bt_hogp_init(&hogp, &hogp_parameters);

    /* STEP 2 init callbacks */
    bt_conn_auth_cb_register();

    /* STEP 3 intit BLE */


    /* STEP 4 init SCANNER */
    
    
    /* STEP 5 start scanner */
}
