<h1 style="text-align: left;"><?php print $title; ?></h1>

<div style="float: left; width: 100%; display: block; margin-bottom: 20px; background-color: #ececec; border: 1px solid #cdcdcd;">
  <div style="float: left; width: 100%; padding-bottom: 15px; padding-left: 15px; padding-right: 15px; display: block;">
    <h5>SUMMARY:</h5>
    <div style="float: left; width: 100%; display: block;">
      <div style="float: left; width: 50%; text-align: left;">
        Order #:
      </div>
      <div style="float: right; width: 50%; text-align: left; color: #8dc73f;">
        <div style="font-weight: bold; text-decoration: underline;">
          <?php print $order_number; ?>
        </div>
      </div>
    </div>
    <div style="float: left; width: 100%; display: block;">
      <div style="float: left; width: 50%; text-align: left;">
        Order Date:
      </div>
      <div style="float: right; width: 50%; text-align: left;">
        <?php print $order_date; ?>
      </div>
    </div>
    <div style="float: left; width: 100%; display: block;">
      <div style="float: left; width: 50%; display: block; text-align: left;">
        Order Total:
      </div>
      <div style="float: right; width: 50%; display: block; text-align: left;">
        <?php print $order_total; ?>
      </div>
    </div>
    <div style="float: left; width: 100%; display: block;">
      <div style="float: left; width: 50%; display: block; text-align: left;">
        <strong>Order Status</strong>:
      </div>
      <div style="float: right; width: 50%; display: block; text-align: left;">
        <strong><?php print $order_status; ?></strong>
      </div>
    </div>

    <?php if ($invoice_number) : ?>
      <div style="float: left; width: 100%; display: block;">
        <div style="float: left; width: 50%; display: block; text-align: left;">
          <strong>Invoice Number</strong>:
        </div>
        <div style="float: right; width: 50%; display: block; text-align: left;">
          <strong><?php print $invoice_number; ?></strong>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($shipping_date) : ?>
      <div style="float: left; width: 100%; display: block;">
        <div style="float: left; width: 50%; display: block; text-align: left;">
          <strong>Shipping Date</strong>:
        </div>
        <div style="float: right; width: 50%; display: block; text-align: left;">
          <strong><?php print $shipping_date; ?></strong>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($shipped_date) : ?>
      <div style="float: left; width: 100%; display: block;">
        <div style="float: left; width: 50%; display: block; text-align: left;">
          <strong>Shipped Date</strong>:
        </div>
        <div style="float: right; width: 50%; display: block; text-align: left;">
          <strong><?php print $shipped_date; ?></strong>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($boxes) : ?>
      <div style="float: left; width: 100%; display: block;">
        <div style="float: left; width: 50%; display: block; text-align: left;">
          <strong>Boxes</strong>:
        </div>
        <div style="float: right; width: 50%; display: block; text-align: left;">
          <strong><?php print $boxes; ?></strong>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($trackings) : ?>
      <div style="float: left; width: 100%; display: block;">
        <div style="float: left; width: 50%; display: block; text-align: left;">
          <strong>Trackings</strong>:
        </div>
        <div style="float: right; width: 50%; display: block; text-align: left;">
          <strong><?php print $trackings; ?></strong>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>

<div style="float: left; width: 100%; display: block; background-color: #8dc73f; margin: 20px 0; padding: 20px 0;">
  <p style="color: white; text-align: center;">
    Call us at <strong><?php print $support_phone; ?></strong> or email us at <strong><a href="mailto:<?php print $support_email; ?>" style="color: white;"><?php print $support_email; ?></a></strong>
  </p>
</div>
