$("#generate").click(function(){

    var string;

    if(Math.random() < 0.5) {
        string = "0"
    }
    else {
        string = "1"
    }

    if(Math.random() < 0.5) {
        string = string + "0"
    }
    else {
        string = string + "2"
    }

    if(Math.random() < 0.5) {
        string = string + "0"
    }
    else {
        string = string + "3"
    }

    if(Math.random() < 0.5) {
        string = string + "0"
    }
    else {
        string = string + "4"
    }

    if(Math.random() < 0.5) {
        string = string + "0"
    }
    else {
        string = string + "5"
    }

    console.log(string)

    $.get("http://www.robertspier.nl/hva/pw3/receive/fire.php", {
        string: string
    },
    function(data, status){
    });
});
