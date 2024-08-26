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

static void bt_auth_display_cb(struct bt_conn *conn, unsigned int passkey){
    printf("Will display passkey and address here")
}

static void bt_auth_confirm_cb(struct bt_conn *conn, unsigned int passkey){
    printf("Passkey confirmed");
}

static void bt_auth_cancel_cb(struct bt_conn *conn){
    printf("Pairing cancelled");
}

struct bt_conn_auth_cb authentication_callbacks = {
    .passkey_confirm = bt_auth_confirm_cb,
    .passkey_display = bt_auth_display_cb ,    
    .cancel = bt_auth_cancel_cb
};

static void pairing_complete(struct bt_conn *conn, bool bonded)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing completed: %s, bonded: %d\n", addr, bonded);
}


static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	printk("Pairing failed conn: %s, reason %d\n", addr, reason);
}

static struct bt_conn_auth_info_cb conn_auth_info_callbacks = {
	.pairing_complete = pairing_complete,
	.pairing_failed = pairing_failed
}; 

int main(void)
{
    int err;

    /* STEP 1 intit hogp*/
    bt_hogp_init(&hogp, &hogp_parameters);

    /* STEP 2 init callbacks */
    err = bt_conn_auth_cb_register(&authentication_callbacks);
    if(err){
        printf("Could not regiester authenticationn callbacks");
        return 0;
    }

    err = bt_conn_auth_info_cb_register(&conn_auth_info_callbacks);
    if(err){
        printf("Could not register authentication info callbacks");
        return 0;
    }

    /* STEP 3 intit BLE */

    err = bt_enable(NULL);
    if(err){
        printf("Could not initiate Bluetooth");
        return 0;
    }

    printf("Bluetooth Initialized");

    /* POTENTIALLY LOAD SETTINGS IF NECESSARY */

    /* STEP 4 init SCANNER */
    scan_init();



    err = bt_scan_start(BT_SCAN_TYPE_SCAN_ACTIVE);
    /* STEP 5 start scanner */
}
