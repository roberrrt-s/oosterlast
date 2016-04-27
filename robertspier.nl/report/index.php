<?php 
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
      $data = $_POST["pot"];

      $timestamp = new DateTime();
      $time = $timestamp->format('Y-m-d H:i:s');

      $message = array("time" => $time, "pot" => $data);


        $inp = file_get_contents('report.json');
        $tempArray = json_decode($inp);
        array_push($tempArray, $message);
        $jsonData = json_encode($tempArray);
        file_put_contents('report.json', $jsonData);

        file_put_contents("output.txt", print_r($message, true) . "\n", FILE_APPEND);
    }
?>
