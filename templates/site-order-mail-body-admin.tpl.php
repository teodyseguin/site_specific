<h1><?php print $title; ?></h1>

<p>Dear <?php print $name; ?>,</p>

<p>
  <?php print $message1; ?><br />
  <?php print $message2; ?>
</p>

<div style="float: left; width: 100%; display: block; margin-bottom: 20px; background-color: #ececec; border: 1px solid #cdcdcd;">
  <div style="float: left; width: 43%; padding-left: 15px; display: block;">
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
  </div>

  <div style="float: right; width: 43%; padding-right: 15px; display: block;">
    <h5>SHIPPING ADDRESS:</h5>
    <p>
      <?php print $name; ?><br />
      <?php print "$address1 $address2"; ?><br />
      <?php print "$city, $country $postal_code"; ?>
    </p>
  </div>
</div>

<table border="0" cellpadding="0" cellspacing="0" style="float: left; width: 100%; display: block; margin-bottom: 20px;">
  <thead style="background-color: #ececec;">
    <tr>
      <th style="width: 20%; padding: 10px 0;"><strong>ITEM</strong></th>
      <th style="width: 25%; padding: 10px 0;">&nbsp;</th>
      <th style="padding: 10px 0;"><strong>QTY</strong></th>
      <th style="padding: 10px 0;"><strong>PRICE</strong></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($products as $product) : ?>
      <?php if (is_array($product)) : ?>
        <tr>
          <td style="text-align: center; padding: 10px 0; border-bottom: 1px solid #cdcdcd;">
            <img src="<?php print $product['image_link']; ?>" style="width: 100px; height: auto;" />
          </td>
          <td style="padding: 10px 0; border-bottom: 1px solid #cdcdcd;">
            <?php print $product['name']; ?><br />
            <a href="<?php print $product['details']; ?>" style="color: #8dc73f;">
              See product details
            </a>
          </td>
          <td style="text-align: center; padding: 10px 0; border-bottom: 1px solid #cdcdcd;">
            <?php print $product['quantity']; ?>
          </td>
          <td style="text-align: center; padding: 10px 0; border-bottom: 1px solid #cdcdcd;">
            <?php print $product['price']; ?>
          </td>
        </tr>
      <?php endif; ?>
    <?php endforeach; ?>
  </tbody>
</table>

<div style="float: left; width: 100%; display: block;">
  <div style="float: left; width: 100%; display: block;">
    <div style="float: left; width: 85%; display: block; text-align: right;">
      Subtotal (# Items):
    </div>
    <div style="float: right; width: 15%; display: block; text-align: right;">
      <?php print $products['subtotal']; ?>
    </div>
  </div>
  <div style="float: left; width: 100%; display: block;">
    <div style="float: left; width: 85%; display: block; text-align: right;">
      Shipping:
    </div>
    <div style="float: right; width: 15%; display: block; text-align: right;">
      <?php print $shipping[0]['shipping']; ?>
    </div>
  </div>
  <div style="float: left; width: 100%; display: block;">
    <div style="float: left; width: 85%; display: block; text-align: right;">
      Tax:
    </div>
    <div style="float: right; width: 15%; display: block; text-align: right;">
      <?php print $tax[0]['tax']; ?>
    </div>
  </div>
  <div style="float: left; width: 100%; display: block;">
    <div style="float: left; width: 85%; display: block; text-align: right; font-weight: bold;">
      Order Total:
    </div>
    <div style="float: right; width: 15%; display: block; text-align: right; font-weight: bold;">
      <?php print $order_total; ?>
    </div>
  </div>
</div>

<div style="float: left; width: 100%; display: block; background-color: #8dc73f; margin: 20px 0; padding: 20px 0;">
  <p style="color: white; text-align: center;">
    Call us at <strong><?php print $support_phone; ?></strong> or email us at <strong><a href="mailto:<?php print $support_email; ?>" style="color: white;"><?php print $support_email; ?></a></strong>
  </p>
</div>
