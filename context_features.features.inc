<?php
/**
 * @file
 * context_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
