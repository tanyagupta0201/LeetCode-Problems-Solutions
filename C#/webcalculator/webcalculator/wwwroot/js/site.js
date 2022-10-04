var firstValue = 0;
var secondValue = 0;
var operationType = "";
var clearRequired = true;
$(document).ready(function () {
    if (clearRequired) {
        $("#outValue").val("0");
    }
    $(".calcBtnD").click(function (e) {
        if (clearRequired) {
            firstValue = $("#outValue").val();
            $("#outValue").val("");
            clearRequired = false;
        }
        $("#outValue").val($("#outValue").val() + e.target.value);
    });

    //Operation onclick 
    $(".calcBtnO").click(function (e) {
        if (e.target.value != 'Equals') {
            operationType = e.target.value;
            clearRequired = true;
        }
    });


    //On submit equals
    $(".calcBtn").click(function (e) {
        let targetValue = e.target.value;
        if (targetValue === 'Percentage') {
            operationType = 'Percentage';
            firstValue = $("#outValue").val();
        }
        if (targetValue === 'Equals' || targetValue === 'Percentage') {
            secondValue = $("#outValue").val();
            $.ajax({
                type: 'POST',
                url: 'Home/Calculation',
                data: { NumberA: firstValue, NumberB: secondValue, OperationType: operationType },
                cache: false,
                success: function (result) {
                    $("#outValue").val(result);
                }
            });
        }
        else if (targetValue === 'PN') {
            let calVal = parseFloat($("#outValue").val());
                $("#outValue").val(-1 * calVal);
        }
        else if (targetValue === 'AC'){
            $("#outValue").val("0");
            firstValue = 0;
            secondValue = 0;
        }
    });
});