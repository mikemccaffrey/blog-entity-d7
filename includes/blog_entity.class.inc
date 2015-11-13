<?php

/**
 * @file
 * Class declarations for the blog entity
 */

/**
 * Define a custom entity class.
 */
class BlogEntity extends Entity {

  /**
   * Overrides defaultUri() to implement a custom default URI
   */
  protected function defaultUri() {
    return array('path' => 'blog-entity/' . $this->identifier());
  }

  /**
   * Override the save function to set uid, created, and upadated properties
   */
  public function save() {

    // Set the created and updated entity properties 
    $this->created = isset($this->created) ? $this->created : REQUEST_TIME;
    $this->updated = REQUEST_TIME;

    // If no uid has been specified, set it to the anonymous uid of 0
    $this->uid = isset($this->uid) ? $this->uid : 0;

    return parent::save();
  }
}

/**
 * Define a custom entity controller class.
 */
class BlogEntityController extends EntityAPIController {

}