<?php
/**
 * @file
 * context_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context01';
  $context->description = 'if role == anonymous && path == <front> --> blocks:search form ';
  $context->tag = '';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-articles_views-block_2' => array(
          'module' => 'views',
          'delta' => 'articles_views-block_2',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('if role == anonymous && path == <front> --> blocks:search form ');
  $export['context01'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context02';
  $context->description = 'if context01 -> add body class';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'context01' => 'context01',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'context02_context01',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('if context01 -> add body class');
  $export['context02'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context03';
  $context->description = 'if menu == APP -> theme_html, blocks';
  $context->tag = '';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'app' => 'app',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'devel-switch_user' => array(
          'module' => 'devel',
          'delta' => 'switch_user',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'user-online' => array(
          'module' => 'user',
          'delta' => 'online',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'context03',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('if menu == APP -> theme_html, blocks');
  $export['context03'] = $context;

  return $export;
}
