<form action="" method="POST" id="createSubmitForm" name="createSubmitForm">
<div class="modal-body">
        <div class="form-group">
            <label for="Name"><b>Name</b></label>
            <input type="text"class="form-control" name="name" value="" placeholder="Enter your name">
            <div class="nameError"></div>
        </div>
        <div class="form-group">
            <label for="Color"><b>Color</b></label>
            <input type="text"class="form-control" name="color"  placeholder="Enter your color">
            <div class="colorError"></div>
        </div>
        <div class="form-group">
            <label for="Transmission"><b>Transmission</b></label>
            <select name="transmission" id="" class="form-control">
                <option value="Automatic">Automatic</option>
                <option value="Manual">Manual</option>
            </select>
        </div>
        <div class="form-group">
            <label for="Price"><b>Price</b></label>
            <input type="text"class="form-control" name="price" value="" placeholder="Enter your price">
            <div class="priceError"></div>
        </div>
</div>
<div class="modal-footer">
    <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
    <button type="submit" class="btn btn-primary">Save Changes</button>
</div>
</form>