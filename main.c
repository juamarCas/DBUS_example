#include <stdio.h>
#include <dbus/dbus.h>

// gcc main.c -o main -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -ldbus-1

int main(){
    printf("Hello world\n");
    DBusConnection *conn = NULL;
    DBusError err;

    dbus_error_init(&err);
    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);

    if (dbus_error_is_set(&err)) { 
      printf("Error: %s\n", err.message); 
      dbus_error_free(&err); 
      exit(1);
    }

    dbus_bus_set_unique_name(conn, "awesomeappiguess");


    const char * busname = dbus_bus_get_unique_name(conn);
    printf("Bus name is %s\n", busname);

    char * name = "juan";
    DBusMessage * msg = dbus_message_new_method_call("example.service", "/example/service", "example.service", "Hello");
    dbus_bool_t res = dbus_message_append_args (msg, DBUS_TYPE_STRING, &name, DBUS_TYPE_INVALID);
    DBusMessage * reply_msg = dbus_connection_send_with_reply_and_block(conn, msg, DBUS_TIMEOUT_USE_DEFAULT, &err);

    if (dbus_error_is_set(&err)) { 
      printf("Error %s\n", err.message); 
      dbus_error_free(&err); 
    }

    dbus_connection_flush(conn);
    dbus_message_unref(msg);

    char * reply = NULL;

    dbus_message_get_args(reply_msg, &err, DBUS_TYPE_STRING, &reply, DBUS_TYPE_INVALID);

    printf("%s\n", reply);

    dbus_message_unref(reply_msg);

    dbus_connection_unref(conn);



    return 0;
}