<?php

/**
 * @file
 *
 * Provides a handler that builds the string for user links we what to use with Linkit core.
 */
class linkit_picker_handler_field_user_info extends views_handler_field {

  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  function render($values) {
    $value = array(
      'path' => linkit_get_insert_plugin_processed_path(linkit_get_active_profile(), 'user/' . $values->uid),
      'title' => $values->users_name
    );
    return drupal_json_encode($value);
  }

}