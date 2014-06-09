<?php

/**
 * @file
 *
 * Provides a handler that builds the string for term links we what to use with Linkit core.
 */
class linkit_picker_handler_field_term_info extends views_handler_field {

  function query() {
    _linkit_picker_set_active_profile();
  }

  function render($values) {
    $value = array(
      'path' => linkit_get_insert_plugin_processed_path(linkit_get_active_profile(), 'taxonomy/term/' . $values->tid),
      'title' => $values->taxonomy_term_data_name
    );
    return drupal_json_encode($value);
  }

}