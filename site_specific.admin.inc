<?php
/**
 * @file
 * site_specific.admin.inc
 */

/**
 * Implements hook_admin().
 */
function site_specific_admin() {
  $form = [];

  $form['environment'] = [
    '#type' => 'fieldset',
    '#title' => t('Environment'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['environment']['environment_mode'] = [
    '#type' => 'textfield',
    '#title' => t('Mode'),
    '#description' => t('Use `local` if under local development. Use `dev` if under dev server. Use `prod` for production server.'),
    '#default_value' => variable_get('environment_mode', ''),
  ];

  $form['unfi_ftp_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('UNFI FTP Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['unfi_ftp_settings']['unfi_ftp_settings_host'] = [
    '#type' => 'textfield',
    '#title' => t('Host IP Address/Name'),
    '#description' => t('The FTP ip address or host domain name'),
    '#default_value' => variable_get('unfi_ftp_settings_host', ''),
  ];

  $form['unfi_ftp_settings']['unfi_ftp_settings_username'] = [
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('The FTP username'),
    '#default_value' => variable_get('unfi_ftp_settings_username', ''),
  ];

  $form['unfi_ftp_settings']['unfi_ftp_settings_password'] = [
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('The FTP password'),
    '#default_value' => variable_get('unfi_ftp_settings_password', ''),
  ];

  $form['email_notifications'] = [
    '#type' => 'fieldset',
    '#title' => t('Email Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['email_notifications']['email_notifications_recipient'] = [
    '#type' => 'textfield',
    '#title' => t('Recipient(s)'),
    '#description' => t('Enter email addresses which will receive notifications via continous operations from the site. For multiple emails, separate them with a `,`'),
    '#default_value' => variable_get('email_notifications_recipient', ''),
  ];

  return system_settings_form($form);
}
