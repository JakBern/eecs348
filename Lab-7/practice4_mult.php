<html>
<head>
<title>Practice 4 Output</title>
</head>
<body>
<?php
$num = (int)$_POST["num"];
echo "<table border='1'>";
for ($i = 0; $i < $num; $i++) {
  echo "<tr>";
  for ($j = 0; $j < $num; $j++) {
      echo "<td>" . ($i + 1) * ($j + 1) . "</td>";
    }
  echo "</tr>";
  }
echo "</table>";
?>
</body>
</html>