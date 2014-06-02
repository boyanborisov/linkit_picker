(function($){

	Drupal.behaviors.linkit_picker_buttons = {
		attach: function(context) {
			$('a.linkit-picker-button:not(.linkit-processed)').addClass('linkit-processed').click(function() {
			  $('#linkit-picker-container a.linkit-picker-button').removeClass('selected');
			  $(this).addClass('selected');
				var viewname = $(this).data('viewname');
				$('#linkit-picker-container .view-container').hide();
				$('#linkit-picker-container .view-linkit-picker-' + viewname).toggle();
				return false;
			});
			$('#linkit-picker-container .view-container:first', context).show();
			$('#linkit-picker-container a.linkit-picker-button:first', context).addClass('selected');
		}
	}

	Drupal.behaviors.linkit_picker = {
		attach: function(context) {
			$('#linkit-picker-container .view-container tr td:not(.linkit-row-processed)').addClass('linkit-row-processed').click(function() {
				var type = $(this).parent().find('.views-field-linkit-picker');
				$('#edit-linkit-path').val($.trim(type.text())).focus();
				Drupal.linkit.requiredFieldsValidation();
				$('html, body').animate({scrollTop:0}, 200);
			});
		}
	}

})(jQuery);