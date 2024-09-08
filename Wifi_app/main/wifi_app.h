/*
 * wifi_app.h
 *
 *  Created on: 31 thg 8, 2024
 *      Author: Huy
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "esp_netif.h"
// Wifi application settings
#define WIFI_AP_SSID				"ESP32_AP" 	//AP NAME
#define WIFI_AP_PASSWORD			"bluesertec" 	// AP PASSWORD
#define WIFI_AP_CHANNEL 	 		1				// AP CHANNEL
#define WIFI_AP_SSID_HIDDEN			0 				//AP VISIBILITY
#define WIFI_AP_BEACON_INTERVAL		100 			// AP BEACON: 100 MILLISECONDS RECOMMENDED
#define WIFI_AP_IP					"192.168.0.1" 	// AP DEFAULT IP
#define WIFI_AP_GATEWAY				"192.168.0.1" 	// AP DEFAUTL GATEWAY (SHOULD BE THE SAME AS THE IP)
#define WIFI_AP_NETMASK				"255.255.255.0" // AP NETMASK
#define WIFI_AP_BANDWIDTH			WIFI_BW_HT20 	// AP BANDWIDTH 20MHZ (40MHZ IS THE OTHER OPTION)
#define WIFI_STA_POWER_SAVE			WIFI_PS_NONE 	// POWER SAVE NOT USE - MORE POWER CONSUMPTION BUT REDUCE LATECY IN REAL-TIME
#define MAX_SSID_LENGTH				32 				//IEEE standard maximum
#define MAX_PASSWORD_LENGTH			64 				// IEEE STANDARD MAXIMUM
#define MAX_CONNECTION_RETRIES		5 				// Retry number on disconnect

// netif object for the Station and Access point
extern esp_netif_t* esp_netif_sta; 	// Station
extern esp_netif_t* esp_netif_ap; 	// Access Point

/**
	* Message IDs for the Wifi application task
*/
typedef enum wifi_app_message
{
	WIFI_APP_MSG_START_HTTP_SERVER = 0,
	WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
	WIFI_APP_STA_CONNECTED_GOT_IP,
} wifi_app_message_e; 	// e mean enum: liệt kê
/**
	* Structure for the message queue
*/
typedef struct wifi_app_queue_message
{
	wifi_app_message_e msgID;
}wifi_app_queue_message_t;
/**
	*Send a message to the queue
*/

BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/**
	*Starts the WiFi RTOS task
*/
void wifi_app_start(void);




#endif /* MAIN_WIFI_APP_H_ */
