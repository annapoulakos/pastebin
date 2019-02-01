var _ = { 
	timer: {},
	gc_timer: {},
	stop: function(){
		clearInterval(this.timer);
		clearInterval(this.gc_timer);
		clearInterval(this.purchase_interval);
	},
	clicks_per_second: 20000,
	fast_cookie_delay: 500,
	fast_cookie: function(){
		var that = this;
		this.timer = setInterval(function(){
			for(var i = 0; i < that.clicks_per_second; i++){
				Game.ClickCookie();
				Game.lastClick = 0;
			}
		}, this.fast_cookie_delay);
	},
	golden_cookie: function(){
		var that = this;
		this.gc_timer = setInterval(function(){
			if(Game.goldenCookie.life>0){
				Game.goldenCookie.click();
			}
		}, 100);
	},

	purchase_interval: 250,
	purchase_bot: function(){
		var that = this;
		this.purchase_timer = setInterval(function(){
			Game.ObjectsById[that.purchase_item()].buy();
		}, that.purchase_interval);
	},
	purchase_item: function(){
		cpc = Number.MAX_VALUE;
		var x = 0;
		cps = 0
		for(i = Game.ObjectsById.length-1; i >= 0; i--){
			var me = Game.ObjectsById[i];
			CpSlower = 0;
			for(j = Game.ObjectsById.length-1; j >= 0; j--){ CpSlower += Game.ObjectsById[j].cps()*Game.ObjectsById[j].amount; }
				me.amount++;
			CpSupper=0;
			for(j = Game.ObjectsById.length-1; j >= 0; j--){ CpSupper += Game.ObjectsById[j].cps()*Game.ObjectsById[j].amount; }
				me.amount--;
			var myCpS = (CpSupper - CpSlower)*Game.globalCpsMult;
			var cpc2 = me.price *(Game.cookiesPs + myCpS) / myCpS;
			if (cpc2 < cpc) {
				cpc = cpc2;
				x = i;
				cps=myCpS
			}
		}

		var time = (Math.round(Game.ObjectsById[x].price) - Game.cookies) / Game.cookiesPs;
		time = time < 0 ? 0 : Beautify(time);

		var numb = (Math.abs(Game.computedMouseCps / Game.cookiesPs));
		numb = numb.toFixed(2);

		var txt = "Buying " + Game.ObjectsById[x].name + " for " +
		Beautify(Math.round(Game.ObjectsById[x].price)) + " at " + Beautify(Math.round(Game.ObjectsById[x].price / (cps*Game.globalCpsMult))) +
		" cookies per CPS!" + "<br>This will take " + time + " seconds without manually clicking." + 
		"<br>Each click would save you " + numb + " seconds.";
		Game.Ticker = txt;
		Game.TickerAge = this.purchase_interval;
		return x;
	}
}