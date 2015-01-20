<?php

function top_users_admin_settings_form($form, &$form_state) {
  $form['top_users_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of posts'),
    '#default_value' => variable_get('top_users_max', 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The maximum number of users to display in the block.'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

function top_users_admin_settings_form_validate($form, &$form_state) {
    $max = $form_state['values']['top_users_max'];
    if (!is_numeric($max)){
        form_set_error('top_users_max', 'You must add a number for the maximum number of users.');
    }
    else if ($max <= 0) {
        form_set_error('top_users_max', 'Please enter a positive number for the maximum number of users.');
    }
}