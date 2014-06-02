<?php

/**
 * @file
 *
 * Provides a handler that builds the string for term links we what to use with Linkit core.
 */
class linkit_picker_handler_field_term_info extends views_handler_field {

  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  function render($values) {
    return 'taxonomy/term/' . $values->tid;
  }

}