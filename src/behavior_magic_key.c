#define DT_DRV_COMPAT zmk_behavior_magic_key

// Dependencies
#include <drivers/behavior.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

#include <zmk/behavior.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

// Instance-Unique Data Struct (Optional)
struct behavior_magic_key_data {
  bool example_data_param1;
  bool example_data_param2;
  bool example_data_param3;
};

// Instance-Unique Config Struct (Optional)
struct behavior_magic_key_config {
  bool example_config_param1;
  bool example_config_param2;
  bool example_config_param3;
};

// Instance Definitions
static struct behavior_magic_key_data behavior_magic_key_data_instance;
static struct behavior_magic_key_config behavior_magic_key_config_instance = {
    .example_config_param1 = true,
    .example_config_param2 = false,
};

// Initialization Function (Optional)
static int on_magic_key_init(const struct device *dev) { return 0; };

// Behavior Function(s)
static int
on_magic_key_binding_pressed(struct zmk_behavior_binding *binding,
                             struct zmk_behavior_binding_event event) {
  LOG_DBG("Magic Key Behavior Activated");
  return 0;
}

static int
on_magic_key_binding_released(struct zmk_behavior_binding *binding,
                              struct zmk_behavior_binding_event event) {
  return 0;
}

// API Structure
static const struct behavior_driver_api magic_key_driver_api = {
    .binding_pressed = on_magic_key_binding_pressed,
    .binding_released = on_magic_key_binding_released};

BEHAVIOR_DT_INST_DEFINE(
    0, // Instance Number (Equal to 0 for behaviors that don't require multiple
       // instances,
       //                  Equal to n for behaviors that do make use of multiple
       //                  instances)
    on_magic_key_init, NULL, // Initialization Function, Power Management //
                             // Device Pointer (Both Optional)
    &behavior_magic_key_data_instance,
    &behavior_magic_key_config_instance, // Behavior Data Pointer, Behavior
                                         // Configuration Pointer (Both
                                         // Optional)
    POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, // Initialization Level,
                                                      // Device Priority
    &magic_key_driver_api);                           // API Structure

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
