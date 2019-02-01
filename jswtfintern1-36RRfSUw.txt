angular.module('whs.application', ['ngSanitize']).value('uiSliderConfig',{}).directive('uiSlider', ['uiSliderConfig', '$timeout','$rootScope', function(uiSliderConfig, $timeout) {
  uiSliderConfig = uiSliderConfig || {};
  return {
    require: 'ngModel',
    compile: function (tElm, tAttrs) {
    return function ($scope, elm, $attrs, ngModel) {
    $scope.valuenow=0;
    function parseNumber(n, decimals) {
      return (decimals) ? parseFloat(n) : parseInt(n);
    }
    // this options variable is used to set and store the range for the slider
    var options = angular.extend($scope.$eval($attrs.uiSlider) || {}, uiSliderConfig);
    // Object holding range values
    var prevRangeValues = {
      min: 0,
      max: 840
    };
    var init = function() {
      // initialize the slider 
      if (angular.isArray(ngModel.$viewValue) && options.range !== true) {
        options.range = true; 
      }   
        // Change here to change default location of THE CHEESE
            options['animate'] = true;
            options['value']   = 0;// was 780
            elm.slider(options);
            angular.element('#placeholder'+0).addClass('active');//was 15
            init = angular.noop;   
    };
    // convenience properties
    var properties = ['min', 'max', 'step'];
     // Find out if decimals are to be used for slider
    var useDecimals = (!angular.isUndefined($attrs.useDecimals)) ? true : false;
      $.each(properties, function(i, property){
      // support {{}} and watch for updates
        $attrs.$observe(property, function(newVal){
          if (!!newVal) {init();
            elm.slider('option', property, parseNumber(newVal, useDecimals));
          }
        });
      });
    // Watch ui-slider (byVal) for changes and update
    $scope.$watch($attrs.uiSlider, function(newVal){init();
      elm.slider('option',newVal);
    }, true);
            // Late-bind to prevent compiler clobbering
    $timeout(init, 0, true);
  /*Update model value from slider*/

  elm.bind('slide', function(event, ui){ngModel.$setViewValue(ui.value);});
  elm.bind('slidestop',function(event,ui){// the current range of slider
   /* for loop to remove the active clas if its present */ 
   for(i= 0; i<$scope.timeline.master.length; i++){
    angular.element('#placeholder'+i).removeClass('active')}
  var  test = ui.value;
  for(i= 0; i<$scope.timeline.master.length; i++){
    if(test>=781){
      var prev            = parseFloat($scope.timeline.master[19].styles.left);
      prev                = prev -50;
      var animateTo = prev * 0.1184835;
      elm.children('a').animate({'left': animateTo+ "%"}, 800, 'swing', function(){});
      angular.element('#placeholder'+19).addClass('active');
      ngModel.$setViewValue(px_range);
      $scope.$emit('update_master', 19);
      break;
    }
    else{
      var px_range = parseFloat($scope.timeline.master[i].styles.left);
      px_range = px_range-50;
          if(Math.round(px_range)==0){
            $scope.$emit('update_master', i);
          }
          else{
            var prev            = parseFloat($scope.timeline.master[i-1].styles.left);
            prev                 = prev -50;
            var forward         = Math.abs(px_range - test);
            var goback          = Math.abs(prev - test);
            if(px_range>=test)
            {
              if( goback > forward){
                var animateTo = px_range * 0.1184835;
                elm.children('a').animate({'left': animateTo+ "%"}, 800, 'swing', function(){});
                angular.element('#placeholder'+i).addClass('active');
                ngModel.$setViewValue(px_range);
                $scope.$emit('update_master', i);
                break;
              }
              else{
                var animateTo = prev * 0.1184835;
                elm.children('a').animate({'left': animateTo+ "%"}, 800, 'swing', function(){});
                angular.element('#placeholder'+(i-1)).addClass('active');
                ngModel.$setViewValue(px_range);
                $scope.$emit('update_master', i-1);
                break;
              }
           }
          }
    } 
    }

        });
$scope.$on('fa_left',    function(event, params){
  var manual_range = parseFloat($scope.timeline.master[params.index].styles.left);
  var animateTo = (manual_range- 50) * 0.1184835;
  //angular.element('#cheese').children('a').css({'left': animateTo+"%"}).animate({'left': animateTo+ "%"}, 800, 'swing', function(){});
  angular.element('#cheese').children('a').animate({'left': animateTo+ "%"})
  ngModel.$setViewValue(manual_range);

   angular.element('#placeholder'+params.lastactive).removeClass('active')
   angular.element('#placeholder'+params.index).addClass('active')
  $scope.$emit('update_master', params.index);
});

    // Update slider from model value
    ngModel.$render = function(){
      init();
      var method = options.range === true ? 'values' : 'value';
      if (!ngModel.$viewValue)
        ngModel.$viewValue = 0;

        // Do some sanity check of range values
        if (options.range === true) {
                    // Check outer bounds for min and max values
                    if (angular.isDefined(options.min) && options.min > ngModel.$viewValue[0]) {
                      ngModel.$viewValue[0] = options.min;
                    }
                    if (angular.isDefined(options.max) && options.max < ngModel.$viewValue[1]) {
                      ngModel.$viewValue[1] = options.max;
                    }

                            // Check min and max range values
                            if (ngModel.$viewValue[0] >= ngModel.$viewValue[1]) {
                        // Min value should be less to equal to max value
                        if (prevRangeValues.min >= ngModel.$viewValue[1])
                          ngModel.$viewValue[0] = prevRangeValues.min;
                        // Max value should be less to equal to min value
                        if (prevRangeValues.max <= ngModel.$viewValue[0])
                          ngModel.$viewValue[1] = prevRangeValues.max;
                      }
                    // Store values for later user
                    prevRangeValues.min = ngModel.$viewValue[0];
                    prevRangeValues.max = ngModel.$viewValue[1];
                  }
                  elm.slider(method, ngModel.$viewValue);
                };
                $scope.$watch($attrs.ngModel, function(){
                  if (options.range === true) {
                    ngModel.$render();
                  }
                }, true);
              };
            }
          };
        }])
.controller('whs.controller', ['$scope', '$rootScope', function($scope, $rootScope){
  $scope.current_index = 0; // CHAGE THIS ALSO WAS 15
  
  $scope.timeline = {
    master: <?= json_encode($timeline); ?>

    , __init__: function(){
      angular.forEach(this.master, function(v, k){
        var calculation =v.days_since_start/8.6964285172;
               v.styles = {left: calculation +50 + 'px'}; 

             })
    }
    ,previouse: function(){
      if($scope.current_index > 0){
        var params = {
          index: $scope.current_index -1,
          lastactive: $scope.current_index

        }
        $scope.$broadcast('fa_left',params);
      }  
    }
    ,next: function(){
      if($scope.current_index < Object.keys(this.master).length){ // was 20
        var params = {
          index: $scope.current_index +1,
          lastactive: $scope.current_index
        }
        $scope.$broadcast('fa_left',params);
      }  
    }
  };
  $scope.timeline.__init__();
  $rootScope.$on('update_master', function(event, params){
    $scope.current_index = params;
   $scope.$apply();
  })

}]);