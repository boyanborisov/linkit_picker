
Drupal.behaviors.linkit_picker_buttons = function(context) {
  $('.linkit_picker_button', context).click(function() {
    var type = $(this).attr('id').replace('edit-','');
    $('#linkit-picker-container .view-container').hide();
    $('#linkit-picker-container .view-linkit-picker-' + type).parent().toggle();
    return false;
  });
}

Drupal.behaviors.linkit_picker = function(context) {
  $('.view-display-id-default tr td', context).click(function() {
    var type = $(this).parent().find('.views-field-linkit-picker');
    $('#edit-link').val($.trim(type.text()));
    //$('#edit-insert').trigger('click');
  });
}
