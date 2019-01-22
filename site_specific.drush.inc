<?php

/**
 * Implements hook_drush_command().
 */
function site_specific_drush_command() {
  $commands['site-specific-stocks-discounts'] = [
    'description' => 'Update the product stocks and discounts',
    'aliases' => ['zssd'],
    'arguments' => [],
    'options' => [],
    'examples' => [],
  ];

  $commands['site-specific-download-image-link'] = [
    'description' => 'Download the images based from the image field link stored on each products',
    'aliases' => ['zsdli'],
    'arguments' => [],
    'options' => [],
    'examples' => [],
  ];

  $commands['site-specific-download-image-link'] = [
    'description' => 'Download the images based from the image field link stored on each products',
    'aliases' => ['zsdli'],
    'arguments' => [],
    'options' => [],
    'examples' => [],
  ];

  $commands['site-specific-update-image-link'] = [
    'description' => 'Update the image link of each products',
    'aliases' => ['zsuil'],
    'arguments' => [],
    'options' => [],
    'examples' => []
  ];

  $commands['site-specific-create-sample-order-file'] = [
    'description' => 'Create a sample order file',
    'aliases' => ['zscsof'],
    'arguments' => [],
    'options' => [],
    'examples' => []
  ];

  $commands['site-specific-connect-ftp'] = [
    'description' => 'Connect to honest greet ftp server',
    'aliases' => ['zscf'],
    'arguments' => [],
    'options' => [],
    'examples' => []
  ];

  $commands['site-specific-parse-invoice'] = [
    'description' => 'Connect to honest greet ftp server',
    'aliases' => ['zspi'],
    'arguments' => [
      'invoice_name' => 'The Invoice file name'
    ],
    'options' => [],
    'examples' => []
  ];

  $commands['site-specific-manual-order-upload'] = [
    'description' => 'Manually upload an order file to UNFI ftp server',
    'aliases' => ['zsmou'],
    'arguments' => [
      'order_number' => 'The order number of the order file',
    ],
    'options' => [],
    'examples' => [],
  ];

  return $commands;
}

/**
 * Sample drush command for parsing an invoice file.
 */
function drush_site_specific_parse_invoice($invoice_name) {
  if (empty($invoice_name)) {
    echo "You need to provide the Invoice file name\n";
    return;
  }

  $local_filepath = "public://site-invoice/" . $invoice_name;

  site_specific_parse_order_shipping_date($local_filepath);
}

/**
 * Manually upload an order file to UNFI FTP server.
 *
 * @param $order_number
 *  The order number of the order file.
 */
function drush_site_specific_manual_order_upload($order_number) {
  if (empty($order_number)) {
    echo "You need to provide the Order number to find the order file.\n";
    return;
  }

  upload_to_ftp($order_number);
}

/**
 * Update the stocks/warehouse field of each products based from the given csv file.
 */
function drush_site_specific_stocks_discounts() {
  $csv = array_map('str_getcsv', file( drupal_get_path('module', 'site_specific') . '/stocks-discounts.csv' ));
  $count = 1;

  foreach ($csv as $row) {
    $sku = $row[0];
    $wh1 = $row[1];
    $discount = $row[2];

    $result = db_query("SELECT product_id FROM commerce_product WHERE sku = $sku")->fetchObject();
    $product = commerce_product_load($result->product_id);
    $product_vars = get_object_vars($product);

    drush_print(dt("$count: Updating the stocks/discounts of product: " . $product->product_id));

    try {
      foreach ($product_vars as $field => $value) {
        if (strpos($field, '_promo_discount') !== FALSE) {
          $product->{$field}[LANGUAGE_NONE][0]['value'] = $discount;
        }
  
        if (strpos($field, '_wh_1') !== FALSE) {
          $product->{$field}[LANGUAGE_NONE][0]['value'] = $wh1;
        }
      }
  
      commerce_product_save($product);
      drush_print(dt("$count: Saved product: " . $product->product_id));
  
      $count++;
    }
    catch (Exception $e) {
      echo $e->getMessage();
    }
  }
}

/**
 * Drush command to download all the images, specified from each product image field.
 */
function drush_site_specific_download_image_link() {
  $destination = '/home/ubuntu/site_images';
  $results = db_query("SELECT product_id FROM commerce_product")->fetchAll();

  if (empty($results)) {
    return;
  }

  foreach ($results as $row) {
    $product = commerce_product_load($row->product_id);
    $product_vars = get_object_vars($product);

    foreach ($product_vars as $field => $value) {
      if (strpos($field, 'product_image') !== FALSE) {
        $image_field_value = $product->{$field}[LANGUAGE_NONE][0]['value'];

        if ($image_field_value != '0' && !empty($image_field_value) && strpos($image_field_value, 'honestgreen') !== false) {
            echo "downloading: $image_field_value\n";
            $filename = basename($product->{$field}[LANGUAGE_NONE][0]['value']);
            $image = file_get_contents($product->{$field}[LANGUAGE_NONE][0]['value']);
            file_put_contents("$destination/$filename", $image);
        }
      }
    }
  }
}

/**
 * Convert the existing honestgreen image url of all products into cloudfront url.
 */
function drush_site_specific_update_image_link() {
  $cloudfront_domain = 'https://d32t7a2u8u5kuj.cloudfront.net';

  $results = db_query("SELECT product_id FROM commerce_product")->fetchAll();

  if (empty($results)) {
    return;
  }

  try {
    foreach ($results as $row) {
      $product = commerce_product_load($row->product_id);
      $product_vars = get_object_vars($product);

      foreach ($product_vars as $field => $value) {
        if (strpos($field, 'product_image') !== FALSE) {
          $image_field_value = $product->{$field}[LANGUAGE_NONE][0]['value'];

          if ($image_field_value != '0' && !empty($image_field_value)) {
            $filename = basename($product->{$field}[LANGUAGE_NONE][0]['value']);

            echo "Converting Honestgreen image url to Cloudfront url: \n";
            echo "[$image_field_value => $cloudfront_domain/$filename]\n\n";

            $product->{$field}[LANGUAGE_NONE][0]['value'] = "$cloudfront_domain/$filename";
            commerce_product_save($product);
          }
        }
      }
    }
  }
  catch (Exception $e) {
    error_log($e->getMessage(), '/var/log/site.error.log');
  }
}

/**
 * Create a sample order file.
 */
function drush_site_specific_create_sample_order_file() {
  $filename = 'test.txt';
  $txt = '';
  $txt .= "1\n";
  $txt .= "1,,1,shampoo\n";
  $txt .= "name,adress1,address2,city,state,postal_code,,ship_code,store_number\n";
  $txt .= "unfi,,quantity,,,\n";
  $txt .= "***EOF***";

  $path = 'public://site-orders/';

  try {
    if (file_prepare_directory($path, FILE_CREATE_DIRECTORY)) {
      file_put_contents($path . $filename, $txt);
    }
    else {}
  }
  catch(Exception $e) {
    echo $e->getMessage();
  }
}

function drush_site_specific_connect_ftp() {
  $customer_id = variable_get('unfi_ftp_settings_username', '');
  $ftp_server = variable_get('unfi_ftp_settings_host', '');
  $password = variable_get('unfi_ftp_settings_password', '');

  $ftp_conn = ftp_connect($ftp_server);

  if (!$ftp_conn) {
    echo 'Unable to connect to FTP';
    return;
  }

  $login = ftp_login($ftp_conn, $customer_id, $password);
  ftp_pasv($ftp_conn, TRUE);

  $contents = ftp_nlist($ftp_conn, ".");

  foreach ($contents as $content) {
    $inside = ftp_nlist($ftp_conn, $content);
    echo "inside $content:\n";
    print_r($inside);
    echo "\n";
    flog_it($inside, "[site_specific]: inside $content");
  }
}
