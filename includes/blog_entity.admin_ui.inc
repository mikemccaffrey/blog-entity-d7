<?php

/**
 * @file
 * Functions needed to use the Entity API Admin UI
 */


/**
 * Create the basic form for adding and editing an entity
 */
function blog_entity_form($form, &$form_state, $entity = NULL) {
  $form = array();

  $form['username'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->title) ? $entity->title : '',
    '#description' => t('Title of this blog entity'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($entity->bid) ? t('Update') : t('Save'),
    ),
  );
  return $form;
}

/**
 * Submit function for the blog_entity_form
 */
function blog_entity_form_submit($form, &$form_state) {
  $blog_entity = entity_ui_form_submit_build_entity($form, $form_state);
  $blog_entity->save();
  $form_state['redirect'] = 'admin/content/blog-entity';
}
