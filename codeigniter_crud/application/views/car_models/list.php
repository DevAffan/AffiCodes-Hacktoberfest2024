<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ajax Crud Application</title>
    <link rel="stylesheet" href="<?php echo base_url(); ?>assets/css/bootstrap.min.css">
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css"> -->

    <script src="<?php echo base_url(); ?>assets/js/jquery-3.7.0.min.js"></script>
    <script src="<?php echo base_url(); ?>assets/js/bootstrap.bundle.min.js"></script>



    <link rel="stylesheet" href="<?php echo base_url(); ?>assets/css/style.css">

</head>

<body>
    <div class="header">
        <h1>Ajax Crud Application</h1>
    </div>
    <div class="container">
        <div class="row pt-4">
            <div class="col-md-6">
                <h4>Car Model</h4>
            </div>
            <div class="col-md-6">
                <a href="javascript:void(0)" onclick="showModal()" class="btn btn-primary " style="float:right">create</a>
            </div>
        </div>
        <div class="col-md-12 pt-2">
            <table class="table table-striped">
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Price</th>
                    <th>Color</th>
                    <th>Transmission</th>
                    <th><button type="" class="btn btn-primary">Edit</button></th>
                    <th><button type="" class="btn btn-danger">Delete</button></th>
                </tr>
            </table>
        </div>
    </div>

   

    <!-- Model -->
    <div class="modal fade" id="createModal" data-backdrop="static" data-keyboard="false" tabindex="-1" aria-labelledby="staticBackdropLabel" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h5 class="modal-title" id="staticBackdropLabel"><b><i>Create Form</i></b></h5>
                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
                <div id="response">

                    </div>
            </div>
        </div>
    </div>
    
</body>

<script>
    function showModal() {
        $("#createModal").modal("show");

        $.ajax({
            url:'<?php echo base_url().'index.php/CarModel/showCreateForm' ?>',
            type:'POST',
            data:{},
            dataType:'json',
            success:function(response){
                $('#response').html(response['html']);
            }
        });
    }

    $('body').on('submit', '#createSubmitForm', function(e){
        e.preventDefault();
        $.ajax({
            url:'<?php echo base_url().'index.php/CarModel/saveModel' ?>',
            type:'POST',
            data:$(this).serializeArray(),
            dataType:'json',
            success:function(response){
                if(response['status'] == 0){
                    if(response['name'] != ''){
                        $('.nameError').html(response['name']).addClass('invalid-feedback d-block');
                        $('#name').addClass('is-invalid');
                    }else{
                        $('.nameError').html('').removeClass('invalid-feedback d-block');
                        $('#name').removeClass('is-invalid');
                    }
                    
                    if(response['color'] != ''){
                        $('.colorError').html(response['color']).addClass('invalid-feedback d-block');
                        $('#color').addClass('is-invalid');
                    }else{
                        $('.colorError').html('').removeClass('invalid-feedback d-block');
                        $('#color').removeClass('is-invalid');
                    }
                    if(response['price'] != ''){
                        $('.priceError').html(response['price']).addClass('invalid-feedback d-block');
                        $('#price').addClass('is-invalid');
                    }else{
                        $('.priceError').html('').removeClass('invalid-feedback d-block');
                        $('#price').removeClass('is-invalid');
                    }

                }
                else{
                    $('.nameError').html('').removeClass('invalid-feedback d-block');
                    $('#name').removeClass('is-invalid');

                    $('.colorError').html('').removeClass('invalid-feedback d-block');
                    $('#color').removeClass('is-invalid');

                    $('.priceError').html('').removeClass('invalid-feedback d-block');
                    $('#price').removeClass('is-invalid');

                }
            }
        }); 

    });

        
</script>

</html>