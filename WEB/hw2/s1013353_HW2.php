<?php

require_once('tcpdf/tcpdf_import.php');
require_once ("tcpdf/tcpdf_barcodes_2d.php");
$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);
$pdf->SetFont('cid0jp','', 18);
$pdf->AddPage();

/*---------------- Your Code Start -----------------*/
$name = $_POST['name'];
$phone = $_POST['phone'];
$want = $_POST['want'];
$city_in = $_POST['city_in'];
$city_out = $_POST['city_out'];
$road = $_POST['road'];
$date = $_POST['date'];
$pizza = $_POST['pizza'];
$allgolf = $_POST['golf'];
$html = <<<EOF

<table border = "1">
<tr>
	<td>姓名：</td>
	<td>$name</td>

	<td>取餐方式</td>
	<td>$want</td>
</tr>

<tr>
	<td>地址：</td>
	<td colspan="6">$city_in $city_out $road</td>
</tr>

<tr>
	<td>電話：</td>
	<td colspan="6">$phone</td>
</tr>

<tr>
	<td>取餐時間</td>
	<td colspan="6">$date</td>
</tr>
<tr>
	<td>披薩</td>
	<td>$pizza 大披薩</td>
	<td>附餐</td>
	<td>if(isset($_POST['golf']) && !empty($_POST['golf']))
    foreach($_POST['golf'] as $golf) $golf;
</td>
</tr>
</table>

<p>訂單Barcode</p>
EOF;
/*---------------- Your Code End -------------------*/

$pdf->writeHTML($html);
$pdf->write1DBarcode("074001726000003006652985", 'C39', '', '', 90, 10, 0.4, '', 'N');
$pdf->lastPage();
$pdf->Output('order.pdf', 'I');
