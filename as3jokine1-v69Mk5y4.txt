package  {	
	
	import flash.display.MovieClip;
	import flash.events.MouseEvent;
	
	public class main extends MovieClip {
		
		public var timesClicked: Number = 0;
		
		public function Main() {
			createBomb();

		}
		public function createBomb() {
			var bomb:MovieClip = new MovieClip();
			bomb.graphics.beginFill(0x0000000);
			bomb.graphics.drawCircle(0,30,25);
			bomb.graphics.endFill();
			bomb.graphics.beginFill(0x000000);
			bomb.graphics.drawRect(-10,0,20,10);
			this.addChild(bomb);
			
			bomb.x = 100;
			bomb.y = 100;
			
			bomb.addEventListener(MouseEvent.CLICK, onBombClick);
			
		}
		public function onBombClick(e:MouseEvent){
			//var someNumber = Number;
			
			this.timesClicked = this.nextRandom()
			if (timesClicked <= 50){

				createBomb;
				return;
			}
			

			bomb.addEventListener(MouseEvent.CLICK, onBombClick);
		}

		protected function nextRandom(){
			var _min: Number = 1;
			var _max: Number = 100;

			return _min + Math.round(Math.random()* (_max - _min))
		}
	}
	
}