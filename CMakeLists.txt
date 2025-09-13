if ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
  target_sources_ifdef(CONFIG_ZMK_BEHAVIOR_MAGIC_KEY app PRIVATE src/behavior_magic_key.c)

  zephyr_include_directories(include)
endif()