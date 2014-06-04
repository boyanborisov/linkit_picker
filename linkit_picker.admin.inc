<?php

/**
 * @file
 * Configuration file for linkit_pikcer module.
 */


/*
 * Linkit picker configuration page
 */
function linkit_picker_config_form($form, &$form_state) {
  $profiles = linkit_profile_load_all();
  $views = _linkit_picker_get_applicable_views();
  $views_options = array();
  foreach ($views as $view) {
    $views_options[$view->name] = empty($views->human_name) ? $view->name : $view->human_name;
  }

  $form['linkit_picker_views'] = array(
    '#type' => 'container',
   	'#tree' => TRUE,
  );

  foreach ($profiles as $profile) {
    $form['linkit_picker_views'][$profile->name] = array(
      '#type' => 'fieldset',
      '#title' => $profile->admin_title,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['linkit_picker_views'][$profile->name]['views'] = array(
      '#type' => 'checkboxes',
      '#title' => t("Linkit picker views"),
      '#options' => $views_options,
      '#default_value' => linkit_picker_get_profile_views($profile->name),
    );
  }

  return system_settings_form($form);
}

/**
 * Returns all views that have linkit picker fields
 */
function _linkit_picker_get_applicable_views() {
  $cache = &drupal_static(__FUNCTION__, array());
  //All predefined linkit picker fiedls
  $linkit_picker_fields = array(
    'linkit_picker_node',
    'linkit_picker_taxonomy',
    'linkit_picker_user'
  );

  if(empty($cache)) {
    $views = views_get_all_views();
    foreach ($views as $view) {
      if(isset($view->display['default'], $view->display['default']->display_options['fields'])) {
        $fields = $view->display['default']->display_options['fields'];
        foreach ($fields as $field) {
          if(isset($field['table']) && in_array($field['table'], $linkit_picker_fields)) {
            $cache[$view->name] = $view;
          }
        }
      }
    }
  }

  return $cache;

}