#ifndef _MAIN_H_
#define _MAIN_H_



#include <list>


/*
  These are defined in IRLIB2 for the Arduino platform, and are
  used here for conistency.
*/
#define UNKNOWN 0
#define NEC 1
#define SONY 2
#define RC5 3
#define RC6 4
#define PANASONIC_OLD 5
#define JVC 6
#define NECX 7
#define SAMSUNG36 8
#define GICABLE 9
#define DIRECTV 10
#define RCMM 11
#define CYKM 12


/*
 *  node_list_t is the container to store each camera node
 *  Uses a doubly linked list:
 *            * Index and search time don't matter
 *            * Simpler to cycle in a list, although simple for an array too
 *            * Despite supporting a ton of devices, realistically looking at max of 5
 */
typedef std::list<node_prop *> node_list_t;
typedef std::list<node_prop *>::iterator node_list_it;

/*
 *  node_list is the global variable to store nodes.
 */
extern node_list_t node_list;

/*
 *  radio module for Raspberry Pi
 */
extern RF24 radio;

/*
 * Initializes the nrf24L01+ radio to default values
 */
void rf24_init();

/*
 *  Sets the nrf24L01+ to match node n's properties then sends packet p
 */
void send_packet(const nrf2401_prop &n, const packet &p);

/*
 * Configures radio to match node n's properties.
 */
void match_node_radio(const nrf2401_prop &n);

/*
 *  Set write address of the raspberry pi
 */
void set_rf24_write_addr(const address_e listening_addr);

/*
 * Handle and process the input of a joystick
 */
void process_input();

  /*
   * Cycle node left
   */
void cycle_node_left( node_list_t &nl, node_list_it &it);

  /*
   *  Cycle node right
   */
void cycle_node_right( node_list_t &nl, node_list_it &it);

void load_config(node_list_t &nl);
void create_ir_packet(node_list_it &it, packet &P, uint32_t ir_code);
void create_motor_packet(node_list_it &it, packet &p);
void print_packet(const packet &p);


#endif
