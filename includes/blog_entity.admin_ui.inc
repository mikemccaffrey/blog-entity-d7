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

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->title) ? $entity->title : '',
    '#description' => t('Title of this blog entity'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  // If editing an existing node, show the additional entity properties
  if(!isset($entity->is_new)) {

    $form['properties'] = array(
      '#type' => 'fieldset',
      '#title' => t('Entity Properties'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => 10,
    );

    $form['properties']['uid'] = array(
      '#type' => 'item',
      '#title' => t('Author UID'),
      '#markup' => $entity->uid,
    );

    $form['properties']['created'] = array(
      '#type' => 'item',
      '#title' => t('Created timestamp'),
      '#markup' => $entity->created,
    );

    $form['properties']['updated'] = array(
      '#type' => 'item',
      '#title' => t('Updated timestamp'),
      '#markup' => $entity->updated,
    );
  }

  // Include the fields provided by the Field API
  field_attach_form('blog_entity', $entity, $form, $form_state);

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

  // Set the uid for the entity to the current user if one has not been previously set
  global $user;
  $blog_entity->uid = isset($blog_entity->uid) ? $blog_entity->uid : $user->uid;

  $blog_entity->save();
  $form_state['redirect'] = 'admin/content/blog-entity';
}
