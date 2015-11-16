# Entity Example for Drupal 7
This module implements a solution for ThinkShout's senior coding test:
http://thinkshout.com/careers/senior-coding-test/

Features include:
- An entity defined in blog_entity_entity_info() named blog_entity (so as not to be confused with the core blog module)
- A base table created in blog_entity_schema() that includes bid, title, uid, created, and updated columns
- Implemented blog_entity_form to build a form for editing blog entities
- Overrode the Entity class save function to save the uid, created, and updated metadata
- Added a body field by default to the entity in blog_entity_install()
- Made the entity fieldable and defined a page for the structure at /admin/structure/blog-entity 
- Used the Entity API Admin UI to show an interface for managing content at /admin/content/blog-entity
- Provided a callback for viewing blog_entities at /blog-entity/BID
- Configured the entity to have a teaser view mode
- Used EntityFieldQuery to display the list of teasers in a 10-item pagenated list at /blog-entity
- Defined a drush command called blog-entity-add-ipsum to add 6 placehoder blog entities at a time for testing

You can view all the steps taken by looking at the individual commits:
https://github.com/mikemccaffrey/blog-entity-d7/commits/master